import pandas as pd
import tensorflow as tf
import numpy as np

# Load the two dataframes
df_si = pd.read_csv('lanczos5_interpolation.csv')
df_tf = pd.read_csv('tf_model_solution_at_epochs_400.csv') # old submitted solution

def blend_solutions(df_si, df_tf):
    y_preds = {}
    ids = []
    for idx in range(len(df_si)):
        fid = df_si['id'][idx]
        ids.append(fid)

        si_d = df_si.iloc[idx][1:].values
        tf_d = df_tf.iloc[idx][1:].values

        si_data = tf.reshape(si_d, [128,128,4])
        tf_data = tf.reshape(tf_d, [128,128,4])

        if (abs(np.max(si_data[:,:,0]) - np.min(si_data[:,:,0])) < 1e-2):
            rho = si_data[:,:,0]
            print(idx, fid, "constant density case")
        else:
            rho = si_data[:,:,0]*0.35 + tf_data[:,:,0]*0.65

        ux  = si_data[:,:,1]*0.35 + tf_data[:,:,1]*0.65
        uy  = si_data[:,:,2]*0.35 + tf_data[:,:,2]*0.65
        uz  = si_data[:,:,3]*0.35 + tf_data[:,:,3]*0.65

        X = tf.stack([rho,ux,uy,uz], axis=2)
        y_preds[fid] = np.array(X).flatten(order='C').astype(np.float32)

    df = pd.DataFrame.from_dict(y_preds,orient='index')
    df['id'] = ids
    #move id to first column
    cols = df.columns.tolist()
    cols = cols[-1:] + cols[:-1]
    df = df[cols]
    #reset index
    df = df.reset_index(drop=True)

    return df


# generate solutions for the test data
df_blend = blend_solutions(df_si, df_tf)
print(df_blend.head())

# generate the output file for submission
df_blend.to_csv('flame_ai_final_blended_solution.csv',index=False)

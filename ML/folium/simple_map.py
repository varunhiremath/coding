import folium
import webbrowser

world_map = folium.Map()

world_map.save("world_map.html")

webbrowser.open("world_map.html")

import math

# Constants
EARTH_RADIUS = 6371000  # radius of the Earth in meters

def haversine_distance(lat1, lon1, lat2, lon2):
    # Convert degrees to radians
    lat1, lon1, lat2, lon2 = map(math.radians, [lat1, lon1, lat2, lon2])
    
    # Haversine formula
    dlat = lat2 - lat1
    dlon = lon2 - lon1
    
    a = math.sin(dlat / 2) ** 2 + math.cos(lat1) * math.cos(lat2) * math.sin(dlon / 2) ** 2
    c = 2 * math.asin(math.sqrt(a))
    
    return EARTH_RADIUS * c

def interpolate(lat1, lon1, lat2, lon2, distance_interval=1):
    # Total distance between the points
    total_distance = haversine_distance(lat1, lon1, lat2, lon2)
    
    # Number of points to interpolate
    num_points = int(total_distance // distance_interval)
    
    # Convert lat/lon to radians
    lat1, lon1, lat2, lon2 = map(math.radians, [lat1, lon1, lat2, lon2])
    
    # Initialize the list of interpolated points
    interpolated_points = []
    
    for i in range(num_points + 1):
        # Interpolation factor
        f = i / num_points
        
        # Interpolated coordinates
        lat = (1 - f) * lat1 + f * lat2
        lon = (1 - f) * lon1 + f * lon2
        
        # Convert back to degrees
        lat_deg = math.degrees(lat)
        lon_deg = math.degrees(lon)
        
        # Append to the list
        interpolated_points.append((lat_deg, lon_deg))
    
    return interpolated_points

# Example usage
lat1, lon1 = 48.7967980732, 1.98697219688  # Point A (in degrees)
lat2, lon2 = 48.7965295287, 1.98669120137   # Point B (in degrees)

interpolated_points = interpolate(lat1, lon1, lat2, lon2)

# Print the length of the interpolated points
print(len(interpolated_points))

# Print first the points
for point in interpolated_points:
    print(point)
    
# Add a third element that is incremented
for i, point in enumerate(interpolated_points):
    interpolated_points[i] = (point[0], point[1], i)

# Print first the points
for point in interpolated_points:
    print(point)


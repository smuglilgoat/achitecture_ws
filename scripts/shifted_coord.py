import math

# Function to calculate the bearing between two lat/lon points
def calculate_bearing(lat1, lon1, lat2, lon2):
    lat1 = math.radians(lat1)
    lon1 = math.radians(lon1)
    lat2 = math.radians(lat2)
    lon2 = math.radians(lon2)

    delta_lon = lon2 - lon1

    x = math.sin(delta_lon) * math.cos(lat2)
    y = math.cos(lat1) * math.sin(lat2) - math.sin(lat1) * math.cos(lat2) * math.cos(delta_lon)

    initial_bearing = math.atan2(x, y)

    # Convert from radians to degrees
    initial_bearing = math.degrees(initial_bearing)
    # Normalize the bearing to 0-360
    bearing = (initial_bearing + 360) % 360

    return bearing

# Function to shift a given latitude and longitude by a certain bearing and distance in meters
def shift_by_bearing(lat, lon, bearing, distance_meters):
    R = 6378137.0  # Earth radius in meters

    # Convert latitude and longitude to radians
    lat_rad = math.radians(lat)
    lon_rad = math.radians(lon)
    
    # Bearing also needs to be converted to radians
    bearing_rad = math.radians(bearing)

    # Distance in radians over Earth's surface
    distance_rad = distance_meters / R

    new_lat_rad = math.asin(math.sin(lat_rad) * math.cos(distance_rad) +
                            math.cos(lat_rad) * math.sin(distance_rad) * math.cos(bearing_rad))

    new_lon_rad = lon_rad + math.atan2(math.sin(bearing_rad) * math.sin(distance_rad) * math.cos(lat_rad),
                                       math.cos(distance_rad) - math.sin(lat_rad) * math.sin(new_lat_rad))

    # Convert the result back to degrees
    new_lat = math.degrees(new_lat_rad)
    new_lon = math.degrees(new_lon_rad)

    return new_lat, new_lon

# Main function to calculate the right and left shifts by 90° and -90°
def shifted_coordinates(lat1, lon1, lat2, lon2, shift_distance):
    # Step 1: Calculate the bearing between the two coordinates
    bearing = calculate_bearing(lat1, lon1, lat2, lon2)

    # Step 2: Calculate bearings for the shifts (right +90° and left -90°)
    right_bearing = (bearing + 90) % 360  # Bearing for rightward shift
    left_bearing = (bearing - 90) % 360   # Bearing for leftward shift

    # Step 3: Calculate new coordinates shifted by 2 meters
    right_shifted = shift_by_bearing(lat2, lon2, right_bearing, shift_distance)
    left_shifted = shift_by_bearing(lat2, lon2, left_bearing, shift_distance)

    return right_shifted, left_shifted

# Shift distance (in meters)
shift_distance = 1

# Example usage
interpolated_points = [
    (48.7967980732, 1.9869721968799998),
    (48.796790613630556, 1.9869643914491664),
    (48.79678315406112, 1.986956586018333),
    (48.796775694491664, 1.9869487805874997),
    (48.796768234922226, 1.9869409751566665),
    (48.79676077535279, 1.9869331697258334),
    (48.79675331578334, 1.986925364295),
    (48.79674585621389, 1.9869175588641665),
    (48.79673839664445, 1.986909753433333),
    (48.796730937075004, 1.9869019480025),
    (48.79672347750555, 1.9868941425716666),
    (48.79671601793612, 1.9868863371408332),
    (48.796708558366674, 1.9868785317100002),
    (48.79670109879723, 1.9868707262791667),
    (48.79669363922778, 1.9868629208483337),
    (48.79668617965833, 1.9868551154174998),
    (48.79667872008889, 1.9868473099866668),
    (48.796671260519446, 1.9868395045558338),
    (48.79666380095001, 1.986831699125),
    (48.796656341380555, 1.986823893694167),
    (48.796648881811116, 1.9868160882633334),
    (48.79664142224167, 1.9868082828325),
    (48.796633962672225, 1.986800477401667),
    (48.79662650310278, 1.9867926719708335),
    (48.79661904353334, 1.98678486654),
    (48.79661158396389, 1.9867770611091669),
    (48.79660412439444, 1.9867692556783334),
    (48.796596664825, 1.9867614502475),
    (48.79658920525556, 1.9867536448166665),
    (48.79658174568611, 1.9867458393858335),
    (48.796574286116666, 1.986738033955),
    (48.79656682654722, 1.9867302285241666),
    (48.796559366977775, 1.9867224230933336),
    (48.796551907408336, 1.9867146176625001),
    (48.79654444783889, 1.9867068122316671),
    (48.796536988269445, 1.9866990068008337),
    (48.7965295287, 1.9866912013700002)
]

# Get the shifted coordinates for each point
shifted_points = []
for i in range(1, len(interpolated_points)):
    right_coords, left_coords = shifted_coordinates(interpolated_points[i-1][0], interpolated_points[i-1][1],
                                                     interpolated_points[i][0], interpolated_points[i][1],
                                                     shift_distance)
    shifted_points.append((right_coords, left_coords))

# Print the shifted points
for i, (right, left) in enumerate(shifted_points):
    print(f"Point {i+1}: Right: {right}, Left: {left}")

# The shifted points can now be used to create a GPX file with the original and shifted coordinates.
# Print the shifted points to the right
print("\nRight:")
for i, (right, left) in enumerate(shifted_points):
    print(f"{right},")

print("\nLeft:")
# Print the shifted points to the left
for i, (right, left) in enumerate(shifted_points):
    print(f"{left},")

# Add a third elemnt that is incremented to each coordinate side
for i, (right, left) in enumerate(shifted_points):
    shifted_points[i] = (right[0], right[1], i), (left[0], left[1], i)

# Print the shifted points with the incremented third element
print("\nRight:")
for i, (right, left) in enumerate(shifted_points):
    print(f"{right},")

print("\nLeft:")
for i, (right, left) in enumerate(shifted_points):
    print(f"{left},")
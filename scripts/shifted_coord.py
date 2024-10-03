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
(48.796381, 1.986531),
(48.79638095884329,1.986530468621055),
(48.79601648488733,1.9861306914370727),
(48.79591229368074,1.9860164081899825),
(48.79590590739818,1.9860135743950025),
(48.79590590739818,1.9860135743950025),
(48.79590590739818,1.9860135743950025),
(48.795898618988645,1.9860120656515505),
(48.795898618988645,1.9860120656515505),
(48.79589220220299,1.9860115466003663),
(48.79589220220299,1.9860115466003663),
(48.79588546594405,1.9860113789625018),
(48.79587828796187,1.9860125524288321),
(48.79587828796187,1.9860125524288321),
(48.79587828796187,1.9860125524288321),
(48.79587144127072,1.9860142288101201),
(48.795864794542666,1.9860179326389016),
(48.795864794542666,1.9860179326389016),
(48.795864794542666,1.9860179326389016),
(48.79585816871045,1.9860227941434232),
(48.795851874169074,1.9860291643898904),
(48.795851874169074,1.9860291643898904),
(48.79584635264081,1.9860350317213147),
(48.79584635264081,1.9860350317213147),
(48.795840211850845,1.986042624203975),
(48.795840211850845,1.986042624203975),
(48.795840211850845,1.986042624203975),
(48.795826696260264,1.986068290093442),
(48.795826696260264,1.986068290093442),
(48.795586528508835,1.9865752318500256),
(48.795586528508835,1.9865752318500256),
(48.79557570625573,1.9866005451979163),
(48.79557570625573,1.9866005451979163),
(48.79557040556,1.9866158002741656),
(48.7955667613312,1.986629211319837),
(48.7955667613312,1.986629211319837),
(48.79556400055145,1.9866427900018095),
(48.79556400055145,1.9866427900018095),
(48.79556400055145,1.9866427900018095),
(48.79556190235874,1.9866593861707145),
(48.79556190235874,1.9866593861707145),
(48.79556057718432,1.986677491081565),
(48.79556057718432,1.986677491081565),
(48.795562286653336,1.9866937138953062),
(48.795562286653336,1.9866937138953062),
(48.79556632761384,1.9867073676744837),
(48.79556632761384,1.9867073676744837),
(48.79557219354558,1.9867202299473945),
(48.79557219354558,1.9867202299473945),
(48.79557845051497,1.986732102798726),
(48.79557845051497,1.986732102798726),
(48.795585880665215,1.9867417989602245),
(48.795585880665215,1.9867417989602245),
(48.795593050107186,1.9867495163133242),
(48.795593050107186,1.9867495163133242),
(48.79560074096244,1.9867570357857858),
(48.79560074096244,1.9867570357857858),
(48.795967648627645,1.9871516477526427),
(48.796168197943985,1.9873673400580287),
(48.796168197943985,1.9873673400580287),
(48.79617742647875,1.9873766962174102),
(48.79617742647875,1.9873766962174102),
(48.79618659215464,1.9873855810357384),
(48.79618659215464,1.9873855810357384),
(48.79619653083728,1.9873932923863151),
(48.79619653083728,1.9873932923863151),
(48.79620426092299,1.9873956016894283),
(48.79620426092299,1.9873956016894283),
(48.79621504478129,1.9873958672311574),
(48.79621504478129,1.9873958672311574),
(48.79622636555351,1.9873890646303494),
(48.79622636555351,1.9873890646303494),
(48.796237568398624,1.9873774286022865),
(48.796237568398624,1.9873774286022865),
(48.79624629482345,1.9873648974955813),
(48.79624629482345,1.9873648974955813),
(48.7962548184515,1.9873520055317044),
(48.7962548184515,1.9873520055317044),
(48.79626730886304,1.9873312321122114),
(48.79626730886304,1.9873312321122114),
(48.79627581194467,1.9873151388582642),
(48.79627581194467,1.9873151388582642),
(48.796283873306294,1.987298207412465),
(48.796283873306294,1.987298207412465),
(48.79653086484504,1.9867648962294027),
(48.79653086484504,1.9867648962294027),
(48.79653329428439,1.9867541673934852),
(48.79653329428439,1.9867541673934852),
(48.796533625571584,1.986742265089788),
(48.79653340471381,1.9867306980646617),
(48.79653340471381,1.9867306980646617),
(48.79653130656163,1.9867186281231),
(48.79653130656163,1.9867186281231),
(48.79652820826894,1.986704811388421),
(48.79652820826894,1.986704811388421),
(48.79652820826894,1.986704811388421),
(48.79652247223606,1.986692811861701),
(48.79652247223606,1.986692811861701),
(48.796515846490735,1.9866819153879476),
(48.796515846490735,1.9866819153879476),
(48.796509552031864,1.9866730305696194),
(48.79650261794683,1.986665497359013),
(48.79650261794683,1.986665497359013),
(48.79638642044657,1.9865378351740048)
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
def main():
    while True:
        L = int(input())
        if L == 0:
            break
        N, C, T = map(int, input().split())
        VR, VT1, VT2 = map(int, input().split())
        charging_stations = list(map(int, input().split()))

        # Calculate the time taken by the rabbit
        time_rabbit = L / VR

        # Calculate the time taken by the tortoise
        time_tortoise = float("inf")
        for i in range(N):
            # Time to reach the charging station
            time_to_station = charging_stations[i] / VT1
            # Remaining distance after reaching the station
            remaining_distance = L - charging_stations[i]
            # Time to reach the end after charging
            time_after_charging = remaining_distance / VT2
            # Total time for this charging station
            total_time = time_to_station + T + time_after_charging
            time_tortoise = min(time_tortoise, total_time)

        if time_tortoise < time_rabbit:
            print("What a pity rabbit!")
        else:
            print("Good job,rabbit!")


if __name__ == "__main__":
    main()

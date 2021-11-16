def eff_cut(log_len, cut_points):
    MAXINT = 0x7fffffff
    cut_points.insert(0, 0)
    cut_points.append(log_len)
    cut_len = list(map(
        lambda x, y: x-y,
        cut_points[1:], cut_points[:-1]
    ))
    cut_len.insert(0, MAXINT)
    cut_len.append(MAXINT)
    print(cut_len[1:len(cut_len)-1])
    cut_pair_sum = list(map(
        lambda x, y: x+y,
        cut_len[1:len(cut_len)-2],
        cut_len[2:len(cut_len)-1]
    ))
    print(cut_pair_sum)
    print()
    total_cost = 0
    while len(cut_len) > 3:
        min_ind = -1
        min_sum = MAXINT
        min_wall = 0
        for i in range(len(cut_pair_sum)):
            if cut_pair_sum[i] < min_sum:
                min_ind = i
                min_sum = cut_pair_sum[i]
                min_wall = max(cut_len[i], cut_len[i+3])
            elif cut_pair_sum[i] == min_sum:
                min_wall_tmp = max(cut_len[i], cut_len[i+3])
                if min_wall_tmp > min_wall:
                    min_ind = i
                    min_sum = cut_pair_sum[i]
                    min_wall = min_wall_tmp
                pass
        cut_len[min_ind+1] = min_sum
        del cut_len[min_ind+2]
        del cut_pair_sum[min_ind]
        print(min_ind)
        if min_ind > 0:
            # print(">(0)")
            cut_pair_sum[min_ind-1] = min_sum + cut_len[min_ind]
        if min_ind < len(cut_pair_sum):
            # print("<(-1)")
            cut_pair_sum[min_ind] = min_sum + cut_len[min_ind+2]
        total_cost += min_sum
        print(cut_len[1:len(cut_len)-1])
        print(cut_pair_sum)
        print()
    return total_cost

if __name__ == "__main__":
    log_num = int(input())
    for _ in range(log_num):
        log_info = list(map(
            int, input().split(" ")
        ))
        print(eff_cut(
            log_info[0],
            list(map(int, input().split(" ")))
        ))
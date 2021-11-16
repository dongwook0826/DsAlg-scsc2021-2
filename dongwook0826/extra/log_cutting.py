def eff_cut(log_len, cut_points):
    cut_points = [0] + cut_points + [log_len]
    cut_len = list(map(
        lambda x, y: x-y,
        cut_points[1:], cut_points[:-1]
    ))
    sub_eff_cut = [[0] * len(cut_len)]
    # print(sub_eff_cut[0])
    for i in range(1, len(sub_eff_cut[0])):
        sub_eff_cut.append([0] * (len(sub_eff_cut[-1])-1))
        for j in range(len(sub_eff_cut[-1])):
            sub_eff_cut[i][j] = min(list(map(
                lambda x: sub_eff_cut[x][j] + sub_eff_cut[i-1-x][j+1+x],
                range(i)
            ))) + sum(cut_len[j:j+i+1])
        # print(sub_eff_cut[i])
    return sub_eff_cut[-1][0]

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
        
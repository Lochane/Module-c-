sorting_check() {
    local nb="$1"
    ARG=$(shuf -i 1-"${nb}" | tr "\n" " ")
    res=$(./PmergeMe $ARG | grep "sorted" | tr -d '\n')
    res2=$(echo "$res" | awk '{printf "%s", substr($0, length($0), 1)}' | tr -d '\n')

    if [[ $res2 =~ ^[^0]*$ ]]; then
        return 0
    else
        echo -e "liste non triée : \n$ARG"
        return 1
    fi
}

loops=${1:-10}
make

for size in 10 50 100 500 1000 2000 3000; do
    all_sorted=true
    for ((i=0; i<loops; i++)); do
        if ! sorting_check "$size"; then
            all_sorted=false
            break 2 # Break out of both loops
        fi
    done
    if $all_sorted; then
        echo "all sorted for $size"
    fi
done
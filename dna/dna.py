import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Error")
        return 1

    # TODO: Read database file into a variable
    table = []
    with open(sys.argv[1]) as f:
        reader = csv.reader(f)
        i = 0
        srt = []
        for row in reader:
            if i == 0:
                for k in range(len(row)):
                    if k == 0:
                        continue
                    srt.append(row[k])
                i = 1
                continue
            for j in range(len(row)):
                if j == 0:
                    continue
                row[j] = int(row[j])
            table += [row]
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as file:
        content = file.read()
    f.closed

    # TODO: Find longest match of each STR in DNA sequence
    longest = []
    for ele in srt:
        longest.append(longest_match(content, ele))
    # TODO: Check database for matching profiles
    k = True
    for person in table:
        for i in range(len(longest)):
            if longest[i] != person[i + 1]:
                k = False
                break
            k = True
        if k == True:
            print(person[0])
            return
    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

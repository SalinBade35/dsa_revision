max_size = 10

def main():
    top = -1
    stack = [0] * max_size

    while True:
        print("Select option:")
        print("1. Push\n2. Pop\n3. Display\n4. Exit")
        n = int(input())

        if n == 1:
            if top == max_size - 1:  # In order to push, stack must have some space
                print("Stack is full")
            else:
                data = int(input("Enter data: "))
                top += 1
                stack[top] = data
                print(f"{stack[top]} is pushed")

        elif n == 2:
            if top == -1:  # In order to pop, stack must have some data
                print("Stack is empty")
            else:
                data = stack[top]
                print(f"{data} is popped")
                top -= 1

        elif n == 3:
            if top == -1:
                print("Stack is empty")
            else:
                print("Displaying the data on stack")
                for x in range(top + 1):
                    print(f" | {stack[x]}", end="")
                print(" | ")

        elif n == 4:
            exit(0)

        else:
            print("Invalid option")

        ch = input("\nDo you want to resume? (yes/Yes/y/Y/YES): ").strip()
        if ch not in ["y", "Y", "yes", "Yes", "YES"]:
            break

if __name__ == "__main__":
    main()

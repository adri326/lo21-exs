# Write a few basic functions to handle a linked list of integers

The required functions are:

- `is_empty(list)`
- `insert_head(list, element)`
- `insert_tail(list, element)`
- `remove_head(list, element)`
- `remove_tail(list, element)`
- `print_list(list)`

## Step 1: Definition

Let `int_ll` be the type defined as follows:

```
struct int_ll {
    int value;
    struct int_ll* next;
};
```

In the above functions, `list` will be a pointer towards `int_ll`.
A null pointer represents an empty list, a null pointer within `int_ll::next` represents the end of the list.

The functions `insert_head`, `insert_tail`, `remove_head` and `remove_tail` will return a (possibly new) pointer to the head of the list, whose value should be retrieved by the caller.

## Step 2: Algorithms

```py
is_empty(list):
    return list == null
```

```py
get_tail(list):
    assert(!is_empty(list))
    tail <- list
    while tail.next != null:
        tail <- list.next
```

```py
insert_head(list, element):
    new_list <- int_ll {
        value: element,
        next: list
    }
    return new_list
```

```py
insert_tail(list, element):
    if is_empty(list):
        return int_ll {
            value: element,
            next: null
        }
    else:
        tail <- get_tail(list)
        tail.next <- int_ll {
            value: element,
            next: null
        }
        return list
```

```py
remove_head(list):
    if is_empty(list):
        free list
        return null
    else:
        next <- list.next
        free list
        return next
```

```py
remove_tail(list):
    if is_empty(list):
        return null
    else if list.next == null:
        free list
        return null
    else:
        tail <- list
        while tail.next.next != null:
            tail <- list.next
        free tail.next
        tail.next = null
        return list
```

```py
print_list(list):
    tail <- list
    print("[")
    while tail != null:
        print(tail.value)
        if tail.next != null:
            print(", ")
        tail <- list.next
    print("]")
```

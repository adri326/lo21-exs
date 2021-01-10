# 2019 Exam, Exercise 1: Student management

## Definitions

- `students`, a list of `Student`s; each `Student` is characterized by the following functions:
  - `name : Student -> String`
  - `general_mean : Student -> ℝ`
  - `choosen_major : Student -> ℕ`
- `majors`, a list of `Major`s; each `Major` is characterized by the following functions:
  - `code : Major -> ℕ`
  - `capacity : Major -> ℕ`
  - `minimum_mean : Major -> ℝ`
- `major`, a single `Major`

## 1. Given a major and a list of student, recursively determine which student may enter this major

We shall encode the return list as a list of the abstract data type `Student'`, described as follows:

- `new_student' : (String, ℝ) -> Student'`
- `name' : Student' -> String`
- `general_mean' : Student' -> ℝ`

Such that:

- `∀n, ∀m, name'(new_student'(n, m)) = n`
- `∀n, ∀m, general_mean'(new_student'(n, m)) = m`

Let `filter_students : Major × List(Student) -> List(Student')` be the algorithm that recursively determines which student may enter a given major:

```
filter_students : (major : Major, students : List(Student)) -> List(Student') :=
    if is_empty(students), then
        return []
    else if
        general_mean(head(students)) < minimum_mean(major)
        || choosen_major(head(students)) != code(major),
    then
        return filter_students(major, pop_head(students))
    else
        return push_head(
            filter_students(major, pop_head(students)),
            new_student'(name(head(students)), general_mean(head(students))
        )
    end if
```

## 2. Given a major's code, a list of majors and a list of students, return the list of students that would be accepted in this major

We first need to sort the students by their general_mean, in decreasing order:
(Note that the original exercise had them sorted already)

```
sort_students : (students: List(Student')) -> List(Student') :=
    tmp_students <- []
    while !is_empty(students), do
        tmp <- head(students)
        students <- pop_head(students)

        while !is_empty(tmp_students) && general_mean'(head(tmp_students)) > general_mean'(tmp), do
            students <- push_head(students, head(tmp_students))
            tmp_students <- pop_head(tmp_students)
        done

        tmp_students <- push_head(tmp)
    done
    return tmp_students
```

This is then the algorithm that returns the list of student names that would be accepted in the given major:

```
accepted_students : (majors : List(Major), code : ℕ, students: List(Student)) -> List(String) :=
    major <- null

    while !is_empty(majors), do
        if code(head(majors)) = code, then
            major <- head(major)
        end if
    done

    assert(major != null)

    students' <- sort_students(filter_students(major, students))

    res : List(String) <- []
    n <- 0

    while n < capacity(major), do
        n <- n + 1
        res <- push_head(res, name'(head(students')))
        students' <- pop_head(students')
    done

    return res
```

## 3. Give the C data structure that holds majors and their respective accepted students

```c
struct student {
    char* name;
    float general_mean;
    struct student* next;
};

struct major {
    int code;
    struct student* students;
    struct major* next;
};

struct university {
    struct major* majors;
};
```

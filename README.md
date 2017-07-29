[![Licence](https://img.shields.io/github/license/JaroslawWiosna/kolakoski.svg)]()
[![Release](https://img.shields.io/github/release/JaroslawWiosna/kolakoski.svg?maxAge=3600)](https://github.com/JaroslawWiosna/kolakoski/releases)
[![GitHub contributors](https://img.shields.io/github/contributors/JaroslawWiosna/kolakoski.svg)]()
# KOLAKOSKI

> [Kolakoski sequence](https://en.wikipedia.org/wiki/Kolakoski_sequence) generator

  - [Overview](#overview)
    - [What is it?](#what-is-it)
    - [How to generate it?](#how-to-generate-it)
  - [With the sequence of length n as input, how long would be the output sequence?](#with-the-sequence-of-length-n-as-input-how-long-would-be-the-output-sequence)
  - [Why can't we start from `2`?](#why-cant-we-start-from-2)
  - [To-Do-List](#to-do-list)

---

## Overview

### What is it?

- [Wikipedia](https://en.wikipedia.org/wiki/Kolakoski_sequence)
- [The on-line encyclopedia of integer sequences](https://oeis.org/A000002)

> Kolakoski sequence is never-ending set of `1` and `2`. 

### How to generate it?

The first element is `1`.

> `{1, ...}`

The next element is `2`, because it can not be `1`. Sequence `{1,1}` is not possible, because we have two the same elements at the begining. The first element tells us how many elements we have, so if we are starting with `1`, there should be a change after.

> `{1, 2}`

What is the next element? So far we know, that the change (from `1` to `2` or from `2` to `1`) should happen after first number. The second number is `2`, which means that there should not be a change after second number. Let's duplicate the second element then.

> `{1, 2, 2}`

That's amazing, because we only need the very first **two** elements to know what are the first **three** elements!
In fact we could tell what is the fourth element: `{1,2}` means that the change is after first (*1*) number and also after third (*1+2=3*) number.

> `{1, 2, 2, 1}`

#### Let's sum up

- `{1, }`
  - `The change after` 
    - `first (1) element`
- `{1, 2, }`
  - `The change after`
    - `first (1)`
    - `and third (1+2) element` 
- `{1, 2, 2, 1}`
  - `The change after`
    - `first (1),`
    - `third (1+2)`
    - `and fifth (1+2+2) element` 
- `{1, 2, 2, 1, 1, 2}`
  - `The change after `
    - `first (1),`
    - `third (1+2),`
    - `fifth (1+2+2),`
    - `sixth (1+2+2+1),`
    - `seventh (1+2+2+1+1)`
    - `and nineth (1+2+2+1+1+2) element` 
- `{1, 2, 2, 1, 1, 2, 1, 2, 2, 1, ...}`


---

## With the sequence of length n as input, how long would be the output sequence?

| input seq | output seq |
|-----------|------------|
| `1`       | `2`        |
| `2`       | `4`        |
| `3`       | `6`        |
| `4`       | `7`        |
| `5`       | `8`        |
| `6`       | `10`       |

The answer is: **You have to sum up all elements and add one**.

Additional question: *What is the percentage increase?*

---

## Why can't we start from `2`?

In fact **we can**.
The outcome would be:

> `{2, 2, 1, 1, 2, 1, 2, 2, 1, ...}`

It looks like the regular sequence without the first element. 

...but how can we be sure? Is there a [mathematical proof](https://en.wikipedia.org/wiki/Mathematical_proof)?


---

### TO-DO LIST

- [x] ~~Sequence of size 100 is generated correctly~~ <-- not relevant from v.0.2.0
- [x] Sequence of size specified by user is generated correctly.
- [x] Sequence is being saved to the file located in dedicated submodule.
- [x] Enable Travis CI
- [ ] Clang support 
- [ ] Generate binary file 
- [ ] Compute (calculate) what is the percentage increase of output sequence with sequence of size `x` as input?

---

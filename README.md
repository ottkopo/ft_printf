
<img width="883" alt="image" src="https://user-images.githubusercontent.com/58331418/201897616-25c8eebc-c054-4959-9b4a-a433138d2a23.png">

**Hive Helsinki Project to recreate libc's printf function**

ft_printf was the first larger project in the Hive curriculum. Printf is quite a large function with many different options that have to work perfectly together. We were tasked with recreating funcitonality for the following conversions: *c, s, p, d, i, o, u, x, X, and f* with flags *hh, h, l, ll, #, 0, space, + and -*. We also had to manage field width and precision.


**How I approached this project**

It became obvious to me early on in the project that building a scalable structure, where you could easily add different functionalities to a central main was the way to go for this project since it has so many different functionalities and they all needed to be treated differently. The approach I took is at the highest level very similar for every variable type. First we read the input, whenever we find a format specifier we first check what type of conversion we need to do. Then we check for all the flags and do the needed actions for those. Finally we check if the variable has precision or field width and act accordingly. Flags, field width and precision work a little bit differently for different variable types so they had to be coded multiple times with differnt logic.


**What I learned**

This project took a long time to make. I learnt a new functionality in the C-language called Variadic functions. This project being very early in the curriculum also taught me how I should act when starting big projects. This was the first project we had that didn't allow me to just dive in head first and start coding, but instead I really had to plan what type of structure I would use for my data and program because choosing the wrong format would surely come and bite me in the ass later on.

Overall this project was very much about polishing all the little details when it came to different flags interacting with eachother.

__attribute__
__attribute__可以设置函数属性(Function Attribute)、变量属性(Variable Attribute)和类型属性(Type Attribute)。__attribute__前后都有两个下划线，并且后面会紧跟一对原括弧，括弧里面是相应的__attribute__参数

__attribute__语法格式为：attribute ( ( attribute-list ) )

如果函数被设定为constructor属性，则该函数会在main（）函数执行之前或者是库被加载时被自动的执行[可以利用该特性做一些初始化操作或者是输出基本信息]；若函数被设定为destructor属性，则该函数会在main（）函数执行之后或者exit（）被调用后被自动的执行。

-ffunction-sections -fdata-sections // 实现按需加载
-fvisibility=hidden -fvisibility-inlines-hidden // 实现符号隐藏
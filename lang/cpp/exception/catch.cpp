void Func()
{
	try
	{
		// 这里的程序代码完成真正复杂的计算工作，这些代码在执行过程中
		// 有可能抛出DataType1、DataType2和DataType3类型的异常对象。
	}
	catch(DataType1& d1)
	{
	}
	catch(DataType2& d2)
	{
	}
	catch(DataType3& d3)
	{
	}
	// 注意上面try block中可能抛出的DataType1、DataType2和DataType3三
	// 种类型的异常对象在前面都已经有对应的catch block来处理。但为什么
	// 还要在最后再定义一个catch(…) block呢？这就是为了有更好的安全性和
	// 可靠性，避免上面的try block抛出了其它未考虑到的异常对象时导致的程
	// 序出现意外崩溃的严重后果，而且这在用VC开发的系统上更特别有效，因
	// 为catch(…)能捕获系统出现的异常，而系统异常往往令程序员头痛了，现
	// 在系统一般都比较复杂，而且由很多人共同开发，一不小心就会导致一个
	// 指针变量指向了其它非法区域，结果意外灾难不幸发生了。catch(…)为这种
	// 潜在的隐患提供了一种有效的补救措施。
	catch(…)
	{
	}
}

def fun():
	grad = input("gradiant please:\n").replace("#", "0x")
	grad = grad.split('","')
	grad[0] = grad[0].replace('["', "")
	grad[-1] = grad[-1].replace('"]', "")
	name = input("funname please:\n")
	res = ""

	with open("colors/header") as f:
		res += f.read()
	res += f"void\t{name}(int *pointer)\n"
	res += "{\n"
	for i in range(len(grad)):
		res += f"\tpointer[{str(i)}] = {grad[i]};\n"
	res += "}\n"
	print(res)
	with open("colors/" + name + ".c", "w") as f:
		f.write(res)
fun()


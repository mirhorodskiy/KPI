using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ooplab2cs
{
	public class MyString
	{
		public MyString(string str) {
			length = str.Length;
			this.str = str;
		}
		public int getStringLength()
		{
			return length;
		}

		public string getString()
		{
			return str;
		}

		public void deleteFirstSpace()
		{
			if (str[0] == ' ')
			{
				str = str.Remove(0,1);
				length--;
			}
		}

		public void deleteLastSpace()
		{
			if (str[length - 1] == ' ')
			{
				str = str.Remove(length - 1, 1);
				length--;
			}
		}

		public int findCoupleSpaces()
		{
			for (int i = 0; i < str.Length - 1; i++)
				if (str[i] == ' ' && str[i + 1] == ' ')
					return i;
			return -1;
		}

		public void deleteCoupleSpaces()
		{
			while (findCoupleSpaces() != -1)
			{
				str = str.Remove(findCoupleSpaces(), 1);
				length--;
			}
		}

		public int countConsonants()
		{
			int count = 0;

			char[] ch = { 'q', 'w', 'r', 't', 'p', 's', 'd', 'f', 'g', 'h', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
			for (int i = 0; i < str.Length; i++)
			{
				for (int j = 0; j < ch.Length; j++)
				{
					if (str[i] == ch[j])
					{
						count++;
					}
				}
			}
			return count;
		}

		private string str;
		private int length;
	};

	public class Text
	{
	public void addStr(MyString str)
		{
			text.Add(str);
		}
		public void printText()
		{
			for (int i = 0; i < text.Count; i++)
				Console.WriteLine(text[i].getString());
		}
		public void deleteStr(MyString str)
		{
			text.Remove(str);
		}
		public void deleteFirstSpaces()
		{
			for (int i = 0; i < text.Count; i++)
				text[i].deleteFirstSpace();
		}

		public void deleteLastSpaces()
		{
			for (int i = 0; i < text.Count; i++)
				text[i].deleteLastSpace();
		}

		public void deleteSpaces()
		{
			for (int i = 0; i < text.Count; i++)
				text[i].deleteCoupleSpaces();
		}

		public int persentOfConsonants()
		{
			int countConsonants = 0;
			int all = 0;
			for (int i = 0; i < text.Count; i++)
			{
				countConsonants += text[i].countConsonants();
				all += text[i].getStringLength();
			}
			return countConsonants * 100 / all;
		}

		private List<MyString> text = new List<MyString>();
	};
	class Program
	{
		static void Main(string[] args)
		{
			Text text1 = new Text();
			MyString str1 = new MyString(" First text line");
			text1.addStr(str1);
			text1.addStr(new MyString("Second   text  line "));
			text1.addStr(new MyString(" Third text line"));
			text1.printText();
			Console.WriteLine("=====================================");
			Console.WriteLine("Percent of consonants letters in text: " + text1.persentOfConsonants());
			text1.deleteFirstSpaces();
			Console.WriteLine("Spaces on the start were deleted");
			text1.deleteLastSpaces();
			Console.WriteLine("Spaces in the end were deleted");
			text1.printText();
			Console.WriteLine("=====================================");
			text1.deleteSpaces();
			Console.WriteLine("Repetitive spaces were deleted");
			text1.printText();
			Console.WriteLine("=====================================");
			Console.WriteLine("Percent of consonants letters in text: " + text1.persentOfConsonants());
			Console.ReadLine();
		}
	}
}

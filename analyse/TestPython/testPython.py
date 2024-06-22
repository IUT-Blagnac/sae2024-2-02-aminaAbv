import unittest
#from simplicite19 import RLE, UNRLE
#from simplicite37 import RLE, UNRLE
#from sobriete19 import RLE, UNRLE

class TestAlgo(unittest.TestCase):

    def testRLE(self):
        self.assertEqual(RLE(""), "")
        self.assertEqual(RLE("abc"), "1a1b1c")
        self.assertEqual(RLE("abbccc"), "1a2b3c")
        self.assertEqual(RLE("aaabaa"), "3a1b2a")
        self.assertEqual(RLE("aAa"), "1a1A1a")
        self.assertEqual(RLE("WWWWWWWWWWWWW"), "9W4W")

    def testRLERecursif(self):
        try:
            self.assertEqual(RLE("", 1), "")
            self.assertEqual(RLE("", 3), "")

            self.assertEqual(RLE("abc", 1), "1a1b1c")
            self.assertEqual(RLE("abbccc", 1), "1a2b3c")
            self.assertEqual(RLE("aaabaa", 1), "3a1b2a")
            self.assertEqual(RLE("aAa", 1), "1a1A1a")

            self.assertEqual(RLE("abc", 2), "111a111b111c")
            self.assertEqual(RLE("abc", 3), "311a311b311c")

            saeIte20 = "111312211312111322212321121113121112131112132112311321322112111312212321121113122112131112131221121321132132211231131122211331121321232221121113122113121122132112311321322112"
            self.assertEqual(RLE("SAE Algo", 20), saeIte20)
        except Exception as e:
            self.fail("Exception inattendue: " + str(e))

    def testUNRLE(self):
        try:
            self.assertEqual(UNRLE(""), "")
            self.assertEqual(UNRLE("1a1b1c"), "abc")
            self.assertEqual(UNRLE("1a2b3c"), "abbccc")
            self.assertEqual(UNRLE("3a1b2a"), "aaabaa")
            self.assertEqual(UNRLE("1a1A1a"), "aAa")
            self.assertEqual(UNRLE("9W4W"), "WWWWWWWWWWWWW")
        except Exception as e:
            self.fail("Exception inattendue: " + str(e))

    def testUNRLERecursif(self):
        try:
            self.assertEqual(UNRLE("", 1), "")
            self.assertEqual(UNRLE("", 3), "")

            self.assertEqual(UNRLE("1a1b1c", 1), "abc")
            self.assertEqual(UNRLE("1a2b3c", 1), "abbccc")
            self.assertEqual(UNRLE("3a1b2a", 1), "aaabaa")
            self.assertEqual(UNRLE("1a1A1a", 1), "aAa")

            self.assertEqual(UNRLE("111a111b111c", 2), "abc")
            self.assertEqual(UNRLE("311a311b311c", 3), "abc")
        except Exception as e:
            self.fail("Exception inattendue: " + str(e))

if __name__ == '__main__':
    unittest.main()

# KMP_Algorithm
*************************************************************************************************************************************************
an algorithm for finding substring among any strings with real great efficiency
**Input**:Any strings and patern are add in the file named input.txt,as below example!
**Output**:just simply creat an blank file named ouput.txt
**Execute**:Compile "kmp_main2.cpp" file in any IDE,it will read the input file and make corresponding output in output.txt 
## Notice ➡️ ###### the number is the base index of substring found in the string;otherwise,(-1) means substring not_found

以下為input.txt內容
若testcases的形式如同下面則可正常執行
*************************************************************************************************************************************************
5

S:hCTwT8RUxbwXmBEAgnkkYcAT74EGCwE4yVryV7UxQ4A9mtvRHqtZdWDMA9ZrQwAEAqSZaUZ4HnT223Y4sUdVGanmPstYtfEh7uQ8b4MPNbucgyyV5Pr7zg5e3EZ4dZSC3s37QfguEvTGKsgHvuZGkyxFr8Ez4abPxfunmuCzfquQ8gf8TMP6dY5AEkTmBSacN6arGg98DghwTQ8u7HHpPHbs2RzVfp83fd4NhsZhxPkpseyfZNYcdbE82cYEz3PxZF8bG5zXtrmwEdVMaEvTc57MyrRm7Byfqxsuy7QCP2kV5VUS6p4zVVYVF2XhpA4sUxsKKzD4QTEuthQcrXcK2EwgEHExmACPcatQTwRh64nr3FXDfD7E8XbaKvBzFdWePraeFP5FT95H97qqv2AdGUS3Nt25Evnm7YnXMkevpeFudyYHEarnD83Rsfz3ZqkZTsAehY3Y2sTbcY93XqD3ZQAhexw3GnpCC8Y4GeHNFr9cRxDenN6PZN7NaCa3Htun
P:xsKKzD4QTEuthQcrXcK2EwgEHExmACPcatQTwR

S:zVfPN77k2pVacnXXwUtAYxUGdSNauKMyUpasrqHF7Hf2VB4rkn9VxwEQk5Uutdxxv5d43avE2yQAWtbRVWzdUQqT4XEF8ZKZahUzy4Yee9mCptpMSz2SMRPqYSZFusyhZpztcXkFvSk8MNVxvacEn7H244F2eU56vtw5Pf2AcSCPWmVRqqs9k7aagWhMZEcnMEFsrx2xkGshQSWmG6rdXGKMAE9sGkPbzVvFnqp22B8aVggpWK6sgk7PC69qrt4MfCvH7ysEphCqMBxSZVPGFbVmds7Pcf43aCs6hQfqSCKq2dQ4aYR6gMrW8Vdv9DzGHU5xRNYsTUCBeKDyw2yCFUcTQUQsEEwSN4tpPtzDyZ6q9C8DDNKYauBY7EthQefaXbC5aZkVFYPxPeeDpzVHRm5AqZDc6CPnAu5cn2tBVH9bwnsqaUtEtCa7dpZYHUEATGN8EHqarwsG8MFBpTTqr49ScRpzG9fESKMSXpYwyPnUV6Vqt6VpcHXYPAE749kV
P:CPnAu5cn2tBVH9bwnsqaUtEtCa7dpZYHUEATGN8EHqarwsG8MFBpTTqr49ScRpzG9fES

S:EbWCRDHDG92Hxf7ctEFGZuVc5ry5yFvTqBtyc3hkHcxrWQBcyUqq2Bek26qzRRMhYYNT64VChUxsHDWp67sG8dgKf6nVWhH5XZPaGNmk7dhYyZGTEvzPvgpDyazNznzUZDg9G4nR4uccNUp5p62zmQQFcUUCacQWndeMAS9uhcbZ8gCPhX9XyYuS6uPaMnNp8kxcXeGVKwf38acEcPe3svBq52kZyhVV3Nq3PFgf9Awk8y79UQvy7VAgrrC37MTgfh5DMKqkTRkkeHTPshYFKs5P2fDPGnAf9SEt54V9ycD86Cb4cWkU7cKxStwZCCHafSRgEYM9v9Vc6XVFKF9FSHRvyFAQWUBYU88QCW8dp6uNuGmsNqTTXFw22xSPBZpkaT5yHbT2FbTSN8xTbn3795bc4dzpgmAEWYTUwUzmgSk6eXqVhyXpCGVkawyUFd98tby5wqc4zkGdYsqYRWXrrTPxTPZwvcyN3QDrUAbh2C46HaTGCwctmFhhEG2kT9Vd
P:ucgyyV5P

S:qnKxCvhbdd4g5kZDK248KNbtvrGcBMKVxWNCUVQtvDxcMv2KxsUhBkePuVMXZQuKxX9sgXDQc3aAmRVvShaNvS2cFeqmXFxuv259fMemFputcNG7nPqeD7Eenzmp5mebSqyvphdMesys6CQHEQeX47vRkBUUQ7ysR9fAXGTnXk4wpXmP3M5NmpauXx33ptrfDFttuSb9ksuYn4NtWCCQt5RdVt6Z5xMaG9yvN5B4qZzEvWunFvk8GAPTXh2UuSaKn8muGx3zBmsSBR5WxfQa2uARVNwDStD3N76xD7WThNszWpTtpkb6V38rpvnrQkdhUkeuH46hREnGRW9ktD4B3PU7DFrmEURTY8mkr4chAD4rqyAesyynYGatmp4GndetPrt3FsDmhBYV9mDGtVEHsYxtV5hDHbtegUsaPfgg4UeY4fFzkY5RweCTVerkR43auwDk5dZkgxTFQPQZRfXwVbPgsZmeg7csahKA7VhtBmfNBNUSsndgGwGSdv7tP5H3
P:pX58eQfB4KKaMHX

S:5sbbuw5drrwsurSS9DpnH6T6vUztHnbduD9tyK7khExbYFAfAhDPzMRHbcSnDB9eqhekMteTE5vTQuAkXQKcmqFDc5UxStESWMKQAdCK22ezQqnXHHvH8bHus8FGUBey6eVeV58WPeFtyr7vA8rxF4RahvGnYGTpyYPtmySt5rMpAGQUxvFpKpX58eQfB4KKaMHXDhCz9tqMHf3hhZ78mwS3FxWbZNuU8ygyH622WYt7HzwQHUxnvqkKWx3stRPyV8gdn5d2BHnP2TMyDwATtc6MVQmbD2dndQ6UUB8CYHDMSdk6RTskrUADCsyvEgdgW3QGAHntN9Tcwp3UnBWv6fRp73XpdBTWpMDYZtPxxa8hMsYptYbHWnaUzYAV3UnnVHZTcscenPGGfppVa9etBF6VU2AZYhVrfyZHSTZ6gw4sSp9q4vcgXBMTxCKdWK7T2VKVDyb9yhfFeKft39kpkxTfGPKps5Q6bdd82ntNvfgPtWX3AGtCQagySDKs9UdR
P:FGUBey6eVeV58WPeFtyr7v
*************************************************************************************************************************************************





output.txt 原本若是空的執行完程式會出現結果如下
**************************************************************************************************************************
test cases:1 is 321

test cases:2 is 413

test cases:3 is -1

test cases:4 is -1

test cases:5 is 122
**************************************************************************************************************************

感謝閱讀 

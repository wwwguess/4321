// Room: /d/heimuya/.c
// write by: dfbb@hero 
// date 97/01/25

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
����ǽ�Ϲ���Ħ��̿�ɽ��ʦ�Ļ���,����һ�Ź�̨�ϣ�
����һֻͭ¯����ֻ����ð�����̵Ĺ���������С�
�����Ǹ��õĵط�.
LONG
	);
set("objects", ([
 __DIR__"obj/jingbook":5,
 ]) );

	set("exits", ([
		"1"  :__DIR__"qlt1",
                "2"  :__DIR__"bht1",
                "3"  :__DIR__"zqt1",
                "4"  :__DIR__"xwt1",
                "5"  :__DIR__"flt1",
                "6"  :__DIR__"tft1",
                "7"  :__DIR__"dht1",
                "8"  :__DIR__"rjt1",
		"east" :__DIR__"dingfeng7",
	]));

	setup();
}


// Room: /d/quanzhou/nanmen.c
//dan
inherit ROOM;

void create()
{
	set("short", "Ȫ������");
	set("long", @LONG
�������Ϸ���һ��Ȫ�ݵ����š���������һƬ��Ұ�� 

LONG
	);

	set("exits", ([
                "north" : __DIR__"zhongxin",
//                  "south" : "/d/xkisland/xiaowu",
	]));


	setup();

}


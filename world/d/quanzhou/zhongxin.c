// Room: /d/quanzhou/zhongxin.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
Ȫ����һ�������ĸ۳ǡ���Ȼ�����ǳ����ģ�����Ҳֻ�ǽŲ������
��������������������ͨ�����ۣ�������һ��С�
LONG
	);

	set("exits", ([
                "north" : __DIR__"beimen",
                "south" : __DIR__"nanmen",
                "east" : __DIR__"dongjie",
                "west" : __DIR__"xijie",
	]));

	set("outdoors", "quanzhou");
	setup();
}


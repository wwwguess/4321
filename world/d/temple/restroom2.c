// Room: /u/k/karrimor/temple/restroom2.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
����һ�乩��ͻ���������ͬ����Ϣ�ҵ��Ŀͷ�, ������ֻ�Ǽ�
���ذڷ��������Ҿ㡣���ŵ��쾮�д��������Ļ��㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "west" : __DIR__"corridor3",
]));

    create_door("west","ľ��","east");
	setup();
}

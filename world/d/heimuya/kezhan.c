// Room: /heimuya/.c
// dfbb 1997/1/24 

inherit ROOM;

void create()
{
	set("short", "˳����ջ");
	set("long", @LONG
���Ǳ����������Ŀ͵꣬�Ǽ����ֺ���,�������̴���ڴ�ЪϢһ��
�õڶ����������.�������ǳ���¡,ǽ�Ϲ���һ������(paizi)��
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);

	set("item_desc", ([
		"paizi" : "˳����ջ���ֺ�\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	        __DIR__"npc/power" : 1,

	]));

	set("exits", ([
		"east" : __DIR__"sancha",
	]));

	setup();
//       call_other( "/clone/board/kezhan_b", "???" );
}


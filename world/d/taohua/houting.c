// Room: /d/new_taohua/houting.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˼���ƫС��������ޣ�һ��ͨ��ͷ���һ��ͨ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north": __DIR__"yonglu1",
  "south" : __DIR__"dating",
  "east" : __DIR__"yushimen",
  "west" : __DIR__"shitang",
]));
    set("objects", ([
       __DIR__"npc/di-zi3" : 3,
     ]));
	

	setup();
	replace_program(ROOM);
}

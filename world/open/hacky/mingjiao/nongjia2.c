// Room: /d/mingjiao/nongjia2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ũ��ס�����ݣ����ڻ谵��
    һ�����������ں��ż���С����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nongjia",
]));
	set("no_clean_up", 0);
    set("objects",([
   __DIR__"npc/oldwoman" :1,
__DIR__"npc/kid.c" :2,
]));

	setup();
	replace_program(ROOM);
}

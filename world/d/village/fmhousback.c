// Room: /d/village/fmhousback.c

inherit ROOM;

void create()
{
	set("short", "ũ���Ժ");
	set("long", @LONG
�ں�Ժ������и���Ȧ����ֻС������������Ժ�����������һ�ż�
����������Ƥ�������ڼ�����ߵĲ������ӵĸ�Ů�������ԼҲ��ļ�
���õ�����ȥ����ȥ��Щ�����������·���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"farmhouse1",
]));
	//set("no_clean_up", 0);
	set("objects", ([
		"/d/village/npc/woman1":1,	
		]) );
	setup();
	//replace_program(ROOM);
}

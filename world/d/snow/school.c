// Room: /d/snow/school.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������һ�������Ժ����Ȼ���ӿ��������Ͼ��ˣ����Ǵ�ɨ�ú�
���࣬ǽ���Ϲ���һ��ɽˮ�����⾳��Ϊ���ף���Ժ�Ĵ��ſ��ڱ��ߣ�
������һ��ľ��ͨ�����ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : "/d/snow/sroad2",
]));

	set("objects", ([
		__DIR__"npc/scholar" : 2,
		__DIR__"npc/teacher": 1 ]) );
	setup();
	replace_program(ROOM);
}

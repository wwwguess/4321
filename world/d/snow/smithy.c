// Room: /d/snow/smithy.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������һ��������ӣ��ӻ�¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬����
�Ľ���������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�ͷ������������
�ȣ����������������õ��������졣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : "/d/snow/mstreet2",
]));

	set("objects", ([
		"/d/snow/npc/smith": 1 ]) );
	setup();
	replace_program(ROOM);
}

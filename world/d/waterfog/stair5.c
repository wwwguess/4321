// Room: /d/waterfog/stair5.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����");
	set("long", @LONG
������������һ�������İ�ʯ�����ϣ���������ɽ��������������
��һ��������ˮ�̸�ʹ����ڱ��ߵ�ɽ�嶥�ϣ���ʹ�Ǵ���ô���ľ���
����Ȼ�о�����¥��ƮƮ���죬����׽����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/d/waterfog/frontyard",
  "eastdown" : "/d/waterfog/clifftop",
]));
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}

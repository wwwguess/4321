// Room: /d/waterfog/wpath1.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
������������һ��ɽ���ϵ�С����������ȥֻ��ɽ��һ����ɫʯ��
������ɽ��ͨ�����߲�Զ����һ��ƽ̨��ƽ̨�ı��߾��Ǻպ���������
��ʥ�ء�ˮ�̸󡹣�С���ı������������һ�ŷ�������������ɽ��ͨ
��λ��ɽ�۵ġ���̨����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/waterfog/wpath2",
  "east" : "/d/waterfog/frontyard",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}

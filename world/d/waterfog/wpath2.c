// Room: /d/waterfog/wpath2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
������������һ��ɽ��С���ϣ����߲�Զ����������ˮ�̸�����ɫ
�����ߣ�С��������һ����ʯ����ͨ��ɽ�۵ĺ�̨���������ǡ�ˮ��ʮ
����֮���������ĺ�ȶ��£�С��������һ���ߡ��˳߸ߵ�ʯ��(stone
)��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/d/waterfog/wpath3",
  "east" : "/d/waterfog/wpath1",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "ʯ�����漸���Ծ����ӵ���д�������ʯ̨���ҳ���ˮ�̸������
��������¥����
����ϸһ�����⼸���ּ�˿��û�и���ۼ������������ֵ���ֱ��
����ָ����ʯ��д����һ�㡣
",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}

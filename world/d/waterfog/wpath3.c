// Room: /d/waterfog/wpath3.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����");
	set("long", @LONG
��������һ����ʯ�����ϣ������������ɽ�ڶ��������߸���һ��
����׵�ɽ�ȿ����������������ɽ��֮�ϵ�ˮ�̸�ÿ���峿ɽ��
�еĳ�������Ʈ�𣬴�������Կ���ˮ�̸��ݷ�Ʈ���Ƽ䣬�����ˮ��
ʮ���еġ�����¥�󡹣�ʯ������ɽ�ڴ�����ת��������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/waterfog/wpath4",
  "southwest" : "/d/waterfog/wpath2",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}

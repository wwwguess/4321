// Room: /d/waterfog/wpath5.c

inherit ROOM;

void create()
{
	set("short", "��ʯ����");
	set("long", @LONG
����������һ������ɽ�ڶ����İ�ʯ�����ϣ�ͨ�����߲�Զ������
��ͤ�����Ǻ�̨����ڣ����ߺͱ��߶�������׵���ȣ�������ȣ�
�����ߵ�Ұ��ɽ��������ɽ��ͼ���롢��ħɽ����Х�¡�ɳ��ɽһֱ��
��Į���������ɵĸ�ɽ����̨�����䲻���ߣ�������������ȵĻ�����
��ȴ����һ��Ⱥɽ���ݵ���������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/waterfog/wpath4",
  "west" : "/d/waterfog/swordtomb",
]));
	set("no_clean_up", 0);
	set("outdoors", "waterfog");

	setup();
	replace_program(ROOM);
}

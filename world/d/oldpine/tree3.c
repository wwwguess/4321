// Room: /d/oldpine/tree3.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��....�������������������������ˣ�һ�������������˷�����
��ʹ������Ŀ���������Ȼ��ľ�������������ֵط����¿���ʮ�ֲ�
�ǵģ������㻹���̲�ס����һ�ۣ��������������Ҳ��ʮ�塢���ɸ�
��һ����ѣ����������ڵ���ȥ��ǰ�뿪����ط���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : "/d/oldpine/tree2",
]));
	set("outdoors", "oldpine");

	setup();
	replace_program(ROOM);
}

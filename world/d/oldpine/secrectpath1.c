// Room: /d/oldpine/secrectpath1.c

inherit ROOM;

void create()
{
	set("short", "����ͨ��");
	set("long", @LONG
��������վ��һ����ʯͨ��֮�У����ϱ���������������ˮ������
��������������̦��һ�ɶ���ӱ��ߴ���������ʲôҰ�ޣ�Ҳ�����
��ͷ��ȥ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"path3",
  "south" : __DIR__"passage",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

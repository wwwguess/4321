// Room: /d/snow/eroad3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
����һ��˵����˵խ��Ҳ��խ��ɽ·��·���ü���������̦��
��ʯ�̳ɣ�������һ���µأ�������������������м��䷿�ݴ�������
ľ�䣬��������ɽ�ڣ�ɽ·�������ν�һ������С������������ͨ��ɽ
�ϵ�ʯ�ס�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : "/d/oldpine/npath1",
  "west" : "/d/temple/sroad",
  "southwest" : __DIR__"eroad2",
]));
	set("no_clean_up", 0);
	set("outdoors", "snow");

	setup();
	replace_program(ROOM);
}

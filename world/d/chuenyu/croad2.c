// Room: /d/chuenyu/croad2.c

inherit ROOM;

void create()
{
	set("short", "·��");
	set("long", @LONG
�����Ǹ�����·�ڣ��������˺ܶࡣ·����һ����ݣ��ǹ���
��ЪϢ�ĵط���
    ������ͨ����ʦ�ı�������������ɼ���ɭ�ĺ���ɽ��������
һ��ͨ�����չصĻ��������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"sunnyroad",
  "southeast" : __DIR__"croad3",
  "northwest" : __DIR__"croad1",
]));
	set("no_clean_up", 0);
	set("outdoors", "chuenyu");

	setup();
	replace_program(ROOM);
}

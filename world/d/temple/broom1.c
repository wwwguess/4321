// Room: /d/temple/broom1.c

inherit ROOM;

void create()
{
    set("short", "��¥");
	set("long", @LONG
���������Ĺ����ղ��鼮�ĵط�, ���ܵ�����϶����������顣
��Щ���Ѿ��ɵ�ֽ�Ŷ�������, ��һ�����ܾͻ�ɢ��������ɷɻҡ�
������ϸ�Ŀ��˿�, �������ﶼֻ��ЩѰ�����޵����鼮, �ƺ�û��
ʲô�ر�ġ���������һ��СС��ľ��ͨ����¥��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/temple/broom2",
  "out" : "/d/temple/road2",
]));

	setup();
	replace_program(ROOM);
}

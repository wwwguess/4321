// Room: /d/hhu/path1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ������������ܷ羰�ǳ�������·������һ������(sign).
LONG
	);
        set("item_desc",([
            "sign":"��ӭ�������ִ���ᣬ���Ƕ�ʮ���;�ʮ������Ͼ��С�\n����·�к�����·������ͨ��Ӻ���ѧ��You are welcome��\n",
        ]));
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"path2.c",
]));
	set("no_clean_up", 0);

	setup();
}

// Room: /d/choyin/tongbhill.c

inherit ROOM;

void create()
{
	set("short", "ͩ��ɽ");
	set("long", @LONG
���������ͩ��,�ʶ��˵�����ϡ��,��ɽ����ʯ������λ��ʿ��®�ڴ�.����ɽ
�����һ��,�ݴ��ǹ���ɽ����������֮��,������������,���ô˵ش�ݲ���.
Ȼ��,һ��������֦��Ҷï,���ھ�ʯ(stone)֮��.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"rockyu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /d/village/lordhouse2.c

inherit ROOM;

void create()
{
	set("short", "�����Ҷ���");
	set("long", @LONG
�����ڵı���ڷ��źܴ�İ����������ӵĺ����ǹ���ع������裬
����������Ĵָ��ϸ��������ȼ�ţ��ع������ƺ�ָ��ǰ���ǽ��(wall)��
�㻹�ǵ�һ�μ�������������ƵĹع�����ǽ�Ǵ�����һ������(stick)��
˳�Ŷ���򿪵Ĵ�������ȥ�����Կ���ԶԶ�Ĺٵ���������������Ⱥ��ң
Զ����ɭ�ĺ���ɽ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lordhouse1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /d/goathill/canyon2.c

inherit ROOM;

void create()
{
	set("short", "Ͽ��");
	set("long", @LONG
������������һ�����������֮�У��������涼�Ǹ߲����ʵ��ͱ�
�����������ȵ�һ��Ǭ�Ե�ɽ������ͨ��Ͽ�ȵĳ��ڣ����ߵ��ͱڴ���
��бб������������ϵ�������������棬���Ƹ���Σ��������ն���
���ߵ��ͱ���ȥ���ߡ��˷֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"northeast" : __DIR__"canyon3",
		"southup" : __DIR__"canyon1",
]));

	setup();
	replace_program(ROOM);
}

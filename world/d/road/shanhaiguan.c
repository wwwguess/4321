
inherit ROOM;

void create()
{
	set("short", "ɽ����");
	set("long", @LONG
����Ǻųơ����µ�һ�ء���ɽ�����ˡ�ɽ���������ﳤ�ǵ���ˣ�
������ɽ������������Ҫ���ǽ����������Ż������ɽ�����Թ���������
���ұ���֮�ء ������Ƕ���ɽ���صı�Ӫ�����򱱴󽫾����Ĺ���ء��
�����ͨ�����������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rshgtoft0",
	"southwest" : "/d/road/rjdtoshg4",
	"east" 		: "/d/shhg/camp1",
]));

	setup();
	replace_program(ROOM);
}

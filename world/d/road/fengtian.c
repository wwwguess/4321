
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ǹ������Ƿ��졣�����ǹ������ĳ��У�����Ἧ�˺ܶ����Թ���
���ص����ˣ��ο͡�������������ĳ��Ž����ţ���֪������ʲô�¡�
�����ǵ�����ɽ��Ψһͨ·��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rfttocbs0",
	"southwest" : "/d/road/rshgtoft4",
	"west" : "/d/road/rfttocy0",
	"east" : "/d/road/rfttogl0",
]));

	setup();
	replace_program(ROOM);
}

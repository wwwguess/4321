
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������������ǣ������϶�����������������������ư��硣
���ﳵˮ���������ַǷ�����������ʱ���ŵ���װ��������
�������������ǵ������ųǡ��������Ϸ�ȥ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rlytoxy3",
	"west" : "/d/road/rxytowds0",
	"northwest" : "/d/wudang/wdroad1",
	"southeast" : "/d/road/rxytohk0",
]));

	setup();
	replace_program(ROOM);
}

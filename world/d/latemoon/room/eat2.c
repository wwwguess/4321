
inherit ROOM;

void create()
{
   set("short", "�ŷ�");
	set("long", @LONG
����һ���ŷ���������˶��Ŵ�Բ������Χ��ʮ���ŵ���ľ���Ρ�
ƽ��ׯ���������ŵĵط��������ǳ������������Ǵ���������Ȼ��
�����������������й��̳��룬Ҳ�����ϵ���Ʒ���д��˼ҵ�����
�븻��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
     "east" :__DIR__"kitchen",
     "west" :__DIR__"eat1",

]));

    set("objects", ([
        "/d/latemoon/obj/wine" : 1,
        "/d/latemoon/obj/food" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}

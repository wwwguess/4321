// duchang2.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
        set("short", "�ĳ�");
	set("long", @LONG
�����Ƕĳ��Ķ�¥���ܶ�����Χ�ż������Ӹ������£�ɷ�����֡�
    �����ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
        );
        set("exits", ([
                "north"          : "/u/cloud/eroad1", 
		"up"		 : "/u/cloud/duchang2",
	 ]) );

        set("item_desc", ([
                "sign": (: look_sign :),
        ]) );

        setup();

}

string look_sign(object me)
{
        return "����д������(bet)��Ӯһ������������ʮ�ġ�\n";
}

void init()
{
        add_action("do_bet", "bet");
}

int do_bet(string arg)
{
	if( !arg || arg=="" ) return "ûǮ�ͱ�ģ�";

	if( random(10) < 8 )
		this_player->add("

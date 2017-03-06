// Room: /d/suzhou/qzhuang.c
//by dwolf
//97.11.4 

#include <ansi.h>
inherit BANK;

string look_paizi();

void create()
{
	set("short", MAG"钱庄"NOR);
	set("long", @LONG
	这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。
墙上挂着一个牌子(paizi)，上面写着些字。
LONG
	);

	set("exits", ([
		"south" : __DIR__"eroad1",
	]));

	set("item_desc" , ([
		"paizi" : (: look_paizi :),
	]));

	set("objects", ([
        	__DIR__"npc/shi2":1,
	]));

	setup();
}

string look_paizi()
{   string s1;
    return "本钱庄实力雄厚，欢迎大家光临。\n" +
              "目前提供服务：\n"+
	      "兑换钱币(convert) \n"+
	      "查账(check) \n" +
	      "存取钱币(cun/qu)。\n";
}


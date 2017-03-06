// huodu.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("��ʦ��", ({ "he shiwo", "he" }) );
        set("title", MAG "ؤ��" NOR + YEL "���" NOR + MAG "����" NOR);
        set("gender", "����" );
        set("shen_type", -1);
        set("age", 28);
        set("str", 25);
        set("con", 25);
        set("dex", 29);
        set("int", 29);
        set("long",
                "����ؤ���½�����ĵ��ӣ���Ҳһ���������������\n�����ļ����ª�����Ͽӿ����ݡ�\n" );

        set("inquiry", ([
                "����"   : (: ask_me :),
        ]) );

        set_skill("blade", 50);
	set_skill("liuhe-dao", 40);
        set_skill("dodge", 40);
	set_skill("xiaoyaoyou", 40);
        set_skill("hand", 30);
	set_skill("shexing-shou", 30);
        set_skill("parry", 50);

	map_skill("blade", "liuhe-dao");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("hand", "shexing-shou");
	map_skill("parry", "liuhe-dao");

	prepare_skill("hand", "shexing-shou");

        setup();

        carry_object("/obj/weapon/gangdao")->wield();
}

string ask_me(object who)
{
        int i;
        object *ob;

        if( query("revealed") ) {
                if( is_killing(who) ) return "���Ȼ֪�����ҵ���֣��������������\n";
                else {
                        kill_ob(who);
                        who->fight_ob(this_object());
                        return "���Ӿ��ǻ������������������ӣ��������ɣ�\n";
                }
        }

        if( (random(10) < 5) || is_fighting() )
                return "�ҡ���֪����\n";

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",  20);
        message("vision",
                HIY "��ʦ������ͻȻ�ų������Ĺ�â������˵��������...�㶼֪���ˣ�\n"
                "��ʦ�Ҵ��һ�����е�����Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ�\n"
 NOR,
                environment(), this_object() );

        set("pursuer", 1);
        set_name("����", ({ "huo du", "huo" }) );
        set("title", MAG "���ַ�����ǰ����" NOR);
        set("long",
                "�����ǽ��ַ����Ķ����ӣ�����Ϊ���Լ�����������ʦ�������ڲ��ˡ�\n");
        set("attitude", "aggressive");
        set("vendetta/authority", 1);
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("bellicosity", 10000);
        set("combat_exp", 40000);
  	ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !userp(ob[i]) ) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
//      carry_object("/d/city/obj/mianju.c");
        set("revealed", 1);
        carry_object("/kungfu/class/gaibang/yuzhu_zhang");
        return "���Ӿ��ǻ������������������ӣ��������ɣ�\n";
}

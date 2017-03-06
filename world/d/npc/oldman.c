#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
        set_name( "����", ({ "old man", "man", "old" }) );
        if( !restore() ) {
                set("short", "��ͩ��ɽ�в�ҩ��" HIC "����" NOR "(old man)");
                set("long",
                        "���׷��Բ�,����ߣ������ߣ��������.\n"
                        "�������ҩ����ɽ������Щ��ͬ����֮����\n"
                        "��ʵ���޷��������ô��ô���֡�\n" );
                set("gender", "����" );
                set("race", "������");
                set("chat_chance", 70);
                set("chat_msg", ({
                        (: this_object(), "random_move" :),
                        CYN "����˵���������ĺ��ӣ��ƣ�\n" NOR,
                        CYN "���߹�µµ���˸�����\n" NOR,
               }) );
                set("chat_msg_coombat", ({
                        CYN "\n���:-)��˵�������ǰ���ɽҩ��.\n" NOR,
                        CYN "\n˵������һ����үү���ҵģ������ɣ�\n" NOR,
                }) );

                // We have 7 pills per reset.
                set("pills", 7);

                // This is the initial apply for his race.
                set("perm_apply", ([
                        "attack":       10,
                        "dodge":        10,
                        "damage":       5,
                ]) );

                set("age", 9);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
                set_skill("unarmed", 1);
                set_skill("dodge", 1);
                set_skill("force", 1);
                set_skill("parry", 1);
        }

        set_temp("apply", query("perm_apply"));
        setup();
        carry_object(__DIR__"obj/kame_suit")->wear();
}

string query_save_file()
{
        return __DIR__"data/oldman";
}

void reset()
{
        int learn;

        // Restore the pills.
        set("pills", 7);
        if( (int)query("potential") > (int)query("learned_points") ) {
                learn = (int)query("potential") - (int)query("learned_points");
                add_temp("apply/attack", learn / 3);
                add_temp("apply/dodge", learn / 3);
                add_temp("apply/damage", learn / 3);
                add("learned_points", (learn / 3) * 3);
        }

        save();
}

int accept_fight(object who)
{
        if( is_fighting() ) {
                if( random(query("eff_kee")) > (int)query("kee") ) {
                        say( CYN "���ߴ�У���ô�����Ҵ�һ�������в��У����Ҵ�
����Щ���ٸ����\n" NOR);
                        return 0;
                } else {
                        say( CYN "���ߴ�У���ô�����Ҵ�һ����û��ϵ����һ����
���Ǻÿ���\n" NOR);
                        return 1;
                }
        }
        return 1;
}

int receive_damage(string type, int pts)
{
        int damage;

        damage = ::receive_damage(type, pts);
        if( (type=="kee") && (damage > (int)query("max_kee") / 5) ) {
                say( CYN "�����������˵ĵط���˵������ʹ��...�������....\n" NOR);
                if( random(query("kee")) < damage)
                        random_move();
        }

        if( (int)query("pills")
        &&      (((int)query("kee")) < 20
                || ((int)query("gin") < 20)
                || ((int)query("sen") < 20) )) {
                say( HIY "���ߴӿڴ�����һ��������è���˸������ɶ�������ȥ��\n
" NOR);
                set("gin", query("eff_gin"));
                set("kee", query("eff_kee"));
                set("sen", query("eff_sen"));
                add("pills", -1);
        }
        return damage;
}

varargs void improve_skill(string skill, int amount, int raw)
{
        // Thus we can gain skill levels from direct fighting.
        ::improve_skill(skill, amount);
}

void revive()
{
        // This is a feature of sungoku's race. See the comic :P.
        add("combat_exp", (int)query("combat_exp") / 3 + 10);
        reset();
        ::revive();
}

void kill_ob(object ob)
{
     int i;
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 50);
        set_temp("apply/parry", 60);
        set_temp("apply/damage", 20);
        set("title", "ͩ��ɽ��  ɽҩ��");
        set("nickname", HIR "�ô��ɽҩ��" NOR);
                HIY "��ҩ�����۷���⣬˵��������Ĳ�ϲ��ɽҩ����
\n\n"
                "�������������Ȼ��ˣ���ͷ�ӽ�����ȥ�ˣ���������\n" NOR
                "\n",
                environment(), this_object() );
        set("pursuer", 1);
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
        set("combat_exp", 50000);
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() ) continue;
                kill_ob(ob[i]);
                ob[i]->fight_ob(this_object());
        }
//        carry_object(__DIR__"obj/tomatoo");
        set("revealed", 1);
        return 0;


}
void defeated_enemy(object ob)
{
        say(CYN "��������һ�� V ���͵����ƣ�˵������Ӯ�ˣ�" NOR);
        remove_killer(ob);
}      









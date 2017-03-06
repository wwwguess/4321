#include <ansi.h>

inherit NPC;
inherit F_SAVE;

void create()
{
        set_name( "����", ({ "old man", "man", "old" }) );
        if( !restore() ) {
                set("short", "��ͩ��ɽ�в�ҩ��" HIC "����" NOR "(old man)");
                set("long",
                        "���׷��Բ�,��̬����.\n"
                        "�������ҩ����ɽ������Щ��ͬ����֮����\n"
                        "������ߣ�������.��ʵ���޷��������ô��ô���֡�\n" );
                set("gender", "����" );
                set("chat_chance", 70);
                set("chat_msg", ({
                        (: this_object(), "random_move" :),
                        CYN "����˵��������������������ĺ��ӣ�������Ƽ��ݵġ�\n" NOR,
                        CYN "���߸��������ͷ�������ݺᡣ\n" NOR,
                        CYN "���������½ǲ��˲��۽ǵ����ᡣ\n" NOR,
               }) );
                set("chat_msg_coombat", ({
                        CYN "\n����˵����ɽҩ��!!���ǰ���!!!!!!\n" NOR,
                        CYN "\n����˵�������⺢�ӳ��ö���ɽҩ������\n" NOR,
                }) );

                set("pills", 9);

                // This is the initial apply for his race.
                set("perm_apply", ([
                        "attack":       10,
                        "dodge":        10,
                        "damage":       5,
                ]) );

                set("age", 99);
                set("str", 44);
                set("cor", 24);
                set("cps", 18);
                set("per", 24);
                set("int", 42);
                set_skill("unarmed", 1);
                set_skill("dodge", 150);
                set_skill("force", 1);
                set_skill("parry", 1);
        }

        set_temp("apply", query("perm_apply"));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{   string item;  
    object foods;
 
 item = "tomatoo";  

 if( !ob || environment(ob)!=environment() ) return;   
 else if( objectp(foods = present(item, ob)) )  {
                tell_object(ob, "�Ҹ����ɽҩ���ó���??\n" NOR );
        }  else  {
                  command("sigh");
                  message_vision("���߸�����$N��ͷ�������ݺᡣ\n ˵��: " +
          "˵������������$N������ĺ��ӣ�������Ƽ��ݵġ�\n" +
          "���߶߶����´ӻ����ó���С��������һ����һ�㣬��һ����һ��.." +
          "����ó���Сɽҩ������$N���\n",ob);   
                foods = new("/d/choyin/npc/obj/tomatoo");
                foods->move(ob);
                ob->set_temp("choyin/ɽҩ��", 1);
                  }
 return;              
}        




void reset()
{
        int learn;

   
        set("pills", 9);
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
set("short", "ͩ��ɽ��  ɽҩ��(yam)"); 
        if( is_fighting() ) {
                if( random(query("eff_kee")) > (int)query("kee") ) {
                        say( CYN "���߲�����������һ����ͣ������������ü����ε��ڵء�\n" NOR);
                        return 0;
                } else {
                        say( CYN "������ɫ�����ҵù̹ܽܽ��㣡��\n" NOR);
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
                say( CYN "�����������˵ĵط����׷�ɢ�ң���ǿ��ס���С�\n" NOR);
                if( random(query("kee")) < damage)
                        random_move();
        }

        if( (int)query("pills")
        &&      (((int)query("kee")) < 20
                || ((int)query("gin") < 20)
                || ((int)query("sen") < 20) )) {
                say( HIY "���ߴӿڴ�����һ����Сɽҩ�����ɶ�������ȥ��\n
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
{   object me;
        me=this_player();      
        set("short", "ͩ��ɽ��  ɽҩ��(yam)"); 

        message_vision("��ҩ�����۷���⣬˵��������Ĳ�ϲ��ɽҩ����??\n\n"
+ "�������������Ȼ��ˣ���ͷ�ӽ�����ȥ�ˣ���������\n" + "ɽҩ��˫��һ�У�һ�ź���ӿ��......\n",me);
        message_vision("ֻ�������项��һ����$N��һ�����ݰ���˳�ȥ����\n",me);
        message_vision("$N���ˡ�\n\n",me);
        message_vision(HIW"���Ź� \n",me);
        message_vision("    �������������������ڡ����Źء���������ǰ������һ���ߴ��\n",me);
        message_vision("��ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷���\n",me);
        message_vision("�������ˡ�\n",me);
        message_vision("    �������Եĳ����� north �� south��\n",me);
        message_vision("���޳�(black gargoyle)\n",me);
        message_vision("���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",me);
        message_vision("���޳�˵����ι�������ģ����ʲô���֣� \n\n",me);
        message_vision("���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n",me);
        message_vision("���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n",me);
        message_vision("���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n",me);
        message_vision("һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n",me);
        message_vision("$N������ʲô�ط������ˣ�ʹ������һ���Լ�����N�ҽ���һ��:�ۣ���ʹ��������������\n",me);
        message_vision("$N���ϵ��������һ��Ȧ�����ڹ�λ�ˡ�\n",me);
        message_vision("����������ɢ��\n",me);
        message_vision("ɽҩ���͵�һ����û�����в�����......\n"NOR,me);
        destruct(this_object());                   
        return 0;


}
void defeated_enemy(object ob)
{       command("fear"); 
        say(CYN "���߹�µµ�͵ش��˸�����˵������Ӯ�ˣ�" NOR);
        remove_killer(ob);
}      




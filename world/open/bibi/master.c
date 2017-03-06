// master.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void use_poison();

void create()
{
        set_name("��ֹƼ", ({ "master dancer", "master", "dancer" }) );

        set("title", "����ׯ��");
        set("nickname", "��������");
        set("gender", "Ů��");
        set("age", 22);
        set("long",
                
"��ֹƼ��һ��ʮ�ֳ�ɫ����Ů��������һ�����ø�������ǧ����\n"
                "�����ӵܣ����̺��Ͷ�Ϊ��������˫����ò�������㵹��\n");
        set("attitude", "peaceful");
        set("class", "dancer");
        set("apprentice_available", 10);

        set("str", 21);
        set("int", 28);
        set("spi", 26);
        set("per", 30);
        set("cps", 30);

        set("force", 1200);
        set("max_force", 1200);
        set("force_factor", 18);

        set("combat_exp", 1000000);
        set("score", 90000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                
"��ֹƼ��ȻһЦ��һ��ת��������������������ǰ�ⳡ���ƺ�ȫ���������ϡ�\n",
                "��ֹƼ�Ų����ƣ������ת�˼���Ȧ������һЦ��\n",
                "��ֹƼ���ַ��˷��Լ��ķ����������±����������Ƶء�\n",
                "��ֹƼЦ������ʰ�����һƬ��" HIM "ħ������" NOR 
"�����µĻ��ꡣ\n",
                (: use_poison :),
                (: exert_function, "chillgaze" :),
        }) );

        set_skill("unarmed", 40);
        set_skill("sword", 70);
        set_skill("throwing", 100);
        set_skill("force", 30);
        set_skill("parry", 70);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("perception", 100);
        set_skill("whip", 100);

        set_skill("stormdance", 100);
        set_skill("tenderzhi", 100);
        set_skill("iceforce", 100);
        set_skill("snowwhip", 90);

        map_skill("dodge", "stormdance");
        map_skill("unarmed", "tenderzhi");
        map_skill("force", "iceforce");
        map_skill("whip", "snowwhip");

        create_family("����ׯ", 1, "ׯ��");

        set_temp("apply/defense", 100);

        setup();

        carry_object(__DIR__"echowhip")->wield();
        carry_object(__DIR__"snake_sandal")->wear();
        carry_object(__DIR__"gold_belt")->wear();
        carry_object(__DIR__"bloody_dress")->wear();
}

void reset()
{
        delete_temp("learned");
        set("apprentice_available", 10);
}

void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say ��ׯ�������Ѿ�����ʮ�����ӣ���������ͽ�ˡ�");
        }
}

void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
                command("say ���˶����Ǻö�����������");
        else {
                command("say �ܺã�ֻҪ��Ա�ׯ�����Ĺ������ô����ٲ��˵ġ�");
                if( (int)ob->query("per") > 25 && (int)ob->query("age") < 20 )
                        
message_vision("$N�����ظ�����$n������˵�����ر�������������Ů�� ....\n", 
this_object(), ob);
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dancer");
        add("apprentice_availavble", -1);
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        if( ob->query_condition("rose_poison") ) return;

        tell_object(ob, 
"����������ƺ�մ����ʲ�ᶫ��������һ��ȴʲ��Ҳû�С�\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("rose_poison", 20);
}
 

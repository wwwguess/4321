// haoshou.c ����

#include <ansi.h>

inherit NPC;

void create()
{
         set_name(MAG "������" NOR + YEL "����" NOR, ({ "hao shou", "haoshou" }));
        set("long", 
                "���������ɵĴ����֡�\n"
                "����������һֻͭ�ţ�������������ش��š�\n");
        set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_kee", 300);
        set("max_gin", 300);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);

//      create_family("������", 3, "������");

        setup();
/*        set("chat_chance", 2);
        set("chat_msg", ({
"����������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ�������御����\n",
"����������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء���\n",
"����������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ���\n",
        }) );
*/

        carry_object("/d/xingxiu/obj/tonghao")->wield();
}


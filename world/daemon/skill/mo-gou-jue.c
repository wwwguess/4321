// mo-jian-jue.c Ä§½£¾÷

inherit SKILL;

mapping *action = ({
(["action":"$NÊ¹Ò»Ê½¡¸ÃÀÈËÈç»¨¡¹£¬ÊÖÖĞ$wÓÉÉÏ¶øÏÂ£¬¹³Ïò$nµÄ$l",
	"force" : 120,
        "dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "ÃÀÈËÈç»¨",
	"damage_type":	"¸îÉË"
]),
(["action":"$NÑüÉíÒ»Å¤£¬Ê¹³ö¡¸ÇàÚ¤Ö®Ìì¡¹£¬¹³¹âÓ³Ñ©,$wÏò$nµÄ$l»ÓÈ¥",
	"force" : 140,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"skill_name" : "ÇàÚ¤Ö®Ìì",
	"damage_type":	"¸îÉË"
]),
([	"action":"$NÒ»Ê½¡¸¾íá¡ÍûÔÂ¡¹£ÊÖÖĞ$w´Ó×óÖÁÓÒ»®Ïò$nµÄ$l",
	"force" : 60,
        "dodge" : 5,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "¾íá¡ÍûÔÂ",
	"damage_type":	"¸îÉË"
]),
([	"action":"$N×İÉíÔ¾Æğ£¬Ò»Ê½¡¸¹ÂµÆ²»Ã÷¡¹½«$wÈ¦×ª,»ô»ôÕ¶Ïò$nµÄ$l",
	"force" : 80,
        "dodge" : 10,
	"damage": 35,
	"lvl" : 27,
	"skill_name" : "¹ÂµÆ²»Ã÷",
	"damage_type":	"¸îÉË"
]),
([	"action":"$NÊÖÖĞ$wÖĞ¹¬Ö±½ø£¬Ò»Ê½¡¸Î¢ËªÆàÆà¡¹£¬¶Ô×¼$nµÄ$l¾ÍÊÇÒ»¹³",
	"force" : 120,
        "dodge" : 15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "Î¢ËªÆàÆà",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$NÊÖÖĞ$wÒ»¶¶£¬Ò»Ê½¡¸ÂçÎ³ÇïÌä¡¹¶Ô×¼$nµÄ$lĞ±Ğ±¹³³ö",
	"force" : 160,
        "dodge" : 5,
	"damage": 45,
	"lvl" : 44,
	"skill_name" : "ÂçÎ³ÇïÌä",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$NÓÒÊÖ$w¶·Éì,Ò»Ê½¡¸äËË®Ö®²¨¡¹´ÌÏò$nµÄ$l",
	"force" : 220,
        "dodge" : 5,
	"damage": 55,
	"lvl" : 52,
	"skill_name" : "äËË®Ö®²¨",
	"damage_type":	"´ÌÉË"
]),
([	"action":"$NÒ»Ê½¡¸Ìì³¤Â·Ô¶»ê·É¿à¡¹£¬$wÃÍµØÏò$nµÄ$l´Ì³ö!",
	"force" : 280,
        "dodge" : 5,
	"damage": 60,
	"lvl" : 60,
	"skill_name" : "Ìì³¤Â·Ô¶»ê·É¿à",
	"damage_type":	"´ÌÉË"
]),
});

int valid_enable(string usage) { return usage == "hook" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 100)
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
	if ((int)me->query_skill("tianmo-dafa", 1) < 20)
		return notify_fail("ÄãµÄÌìÄ§´ó·¨¹¦Á¦²»¹»! £\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("mo-gou-jue",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hook")
		return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
	if ((int)me->query("kee") < 50)
		return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·Ä§½£¾÷!\n");
	me->receive_damage("kee", 25);
	return 1;
}

string *parry_msg = ({
        "$nÒ»¶¶$v£¬ÊÖÖĞµÄ$v»¯×÷Ò»Ìõ³¤ºç£¬¿Ä¿ªÁË$NµÄ$w¡£\n",
        "$n»ÓÎè$v£¬ÊÖÖĞµÄ$v»¯×öÂşÌìÑ©Ó°£¬µ´¿ªÁË$NµÄ$w¡£\n",
        "$nÊÖÖĞµÄ$vÒ»¶¶£¬Ïò$NµÄÊÖÍóÏ÷È¥¡£\n",
        "$n½«ÊÖÖĞµÄ$vÎèµÃÃÜ²»Í¸·ç£¬·â×¡ÁË$NµÄ¹¥ÊÆ¡£\n",
        "$n·´ÊÖ»Ó³ö$v£¬Õû¸öÈËÏûÊ§ÔÚÒ»ÍÅ¹âÃ¢Ö®ÖĞ¡£\n",
});

string *unarmed_parry_msg = ({
        "$nÃÍ»÷$NµÄÃæÃÅ£¬±ÆµÃ$NÖĞÍ¾³·»Ø$w¡£\n",
        "$nÒÔÊØÎª¹¥£¬ÃÍ»÷$NµÄÊÖÍó¡£\n",
        "$n×óÊÖÇáÇáÒ»ÍĞ$N$w£¬ÒıÆ«ÁË$N$w¡£\n",
        "$n½Å×ßÒõÑô£¬¹¥$NÖ®±Ø¾È¡£\n",
        "$n×óÈ­»÷ÏÂ£¬ÓÒÈ­×Ô±££¬½«$N·âÓÚ³ßÍâ¡£\n",
        "$nË«È­Æë³ö£¬$NµÄ¹¦ÊÆÈëÄàÅ£Èëº££¬ÏûÊ§µÃÎŞÓ°ÎŞ×Ù¡£\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
